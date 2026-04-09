CC = gcc
CFLAGS = -Wall -Wextra
CPPFLAGS := -Iinclude -MMD -MP
LDFLAGS = -lm 

TARGET =  teste

SRCDIR = src
OBJDIR = obj

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS := $(OBJS:.o=.d)

all: $(TARGET)
	@echo "> Resultado: SUCESSO"

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)
	@echo "> Compilação do executável: SUCESSO"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	@echo "> Compilação dos objetos: SUCESSO"

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(TARGET)

-include $(DEPS)
