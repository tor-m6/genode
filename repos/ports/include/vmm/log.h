/*
 * \brief  Utilities for implementing VMMs on Genode/NOVA
 * \author Norman Feske
 * \date   2013-08-20
 */

/*
 * Copyright (C) 2013-2017 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#ifndef _INCLUDE__VMM__PRINTF_H_
#define _INCLUDE__VMM__PRINTF_H_

/* Genode includes */
#include <base/thread.h>
#include <base/log.h>

/* NOVA includes */
#include <nova/syscalls.h>

namespace Vmm {

	using namespace Genode;

	/**
	 * Print message while preserving the UTCB content
	 */
	template <typename... ARGS>
	void log(ARGS... args)
	{
		struct Utcb_backup { char buf[Nova::Utcb::size()]; };

		static Mutex       mutex;
		static Utcb_backup utcb_backup;

		Mutex::Guard guard(mutex);

		utcb_backup = *(Utcb_backup *)Thread::myself()->utcb();

		Genode::log("VMM: ", args...);

		*(Utcb_backup *)Thread::myself()->utcb() = utcb_backup;
	}

	template <typename... ARGS>
	void warning(ARGS... args)
	{
		struct Utcb_backup { char buf[Nova::Utcb::size()]; };

		static Mutex       mutex;
		static Utcb_backup utcb_backup;

		Mutex::Guard guard(mutex);

		utcb_backup = *(Utcb_backup *)Thread::myself()->utcb();

		Genode::warning("VMM: ", args...);

		*(Utcb_backup *)Thread::myself()->utcb() = utcb_backup;
	}

	template <typename... ARGS>
	void error(ARGS... args)
	{
		struct Utcb_backup { char buf[Nova::Utcb::size()]; };

		static Mutex       mutex;
		static Utcb_backup utcb_backup;

		Mutex::Guard guard(mutex);

		utcb_backup = *(Utcb_backup *)Thread::myself()->utcb();

		Genode::error("VMM: ", args...);

		*(Utcb_backup *)Thread::myself()->utcb() = utcb_backup;
	}
}

#endif /* _INCLUDE__VMM__PRINTF_H_ */
