.PHONY: suball
suball:
	@for dir in $(SUBDIRS); do \
		echo Making stuff in $$dir; \
		if $(MAKE) -C $$dir all; then \
			true; \
		else \
			exit 1; \
		fi; \
	done;

.PHONY: subclean
subclean:
	@for dir in $(SUBDIRS); do $(MAKE) -C $$dir clean; done;

.PHONY: subformat
subformat:
	@for dir in $(SUBDIRS); do $(MAKE) -C $$dir format; done;
