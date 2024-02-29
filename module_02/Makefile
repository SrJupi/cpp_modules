SUBDIRS := $(wildcard ex*/.)

.PHONY: all clean fclean $(SUBDIRS)

all clean fclean: $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) -C $@ $(MAKECMDGOALS)
