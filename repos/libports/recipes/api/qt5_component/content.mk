MIRROR_FROM_REP_DIR := include/qt5_component \
                       lib/symbols/qt5_component

content: $(MIRROR_FROM_REP_DIR) LICENSE

$(MIRROR_FROM_REP_DIR):
	$(mirror_from_rep_dir)

LICENSE:
	cp $(GENODE_DIR)/LICENSE $@
