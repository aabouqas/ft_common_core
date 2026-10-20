FOLDERS = $(shell ls -d */)

all:
	@n=0
	@for folder in $(FOLDERS); do \
  		if [ -f $$folder/Makefile ]; then \
  		  	name=$$(printf "%02d" $$n);\
			make -C $$folder NAME=$$name;\
			mv $$folder$$name .;\
		fi; \
		n=$$(($$n+1));\
	done;\

clean:
	@for folder in $(FOLDERS); do \
		if [ -f $$folder/Makefile ]; then \
        	make -C $$folder clean ; \
        fi; \
	done; \


re: fclean all

fclean:
	@n=0
	@for folder in $(FOLDERS); do\
		if [ -f $$folder/Makefile ]; then \
        	make -C $$folder fclean ; \
			rm -f $$(printf "%02d" $$n);\
        fi; \
		n=$$(($$n + 1));\
	done;\

push: fclean
	git add .;\
    git commit -m "done";\
    git push\

.PHONY: fclean