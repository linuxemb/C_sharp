CC=gcc	
CFLAGS:=-g
SRC :=$(wildcard *.c)
OBJS :=$(patsubst %.c,%.o,$(SRC))
DEPS:=$(pathsubt %.o,%.d,$(OBJS))
LIBS:=m
EXEC:=getsoc


$(EXEC):$(OBJS)
	gcc  -o$@ $^ $(addprefix -l,$(LIBS))
-include $(DEPS)
.PHONE: clean distclean
clean:
	@rm -f *.o
	@rm -f *.d
distclean:clean
	@rm exec
 

