SRC = src
FILES = $(SRC)/Makefile $(SRC)/truthtable.c

testall:
	./grader.py

1:
	./grader.py --stop
	
normal:
	./grader.py truthtable:1

extra:
	./grader.py truthtable:2

clean:
	rm -rf build pa4.tar

tree: $(FILES)

$(SRC)/Makefile:
	mkdir -p $(dir $@)
	cp data/template.mk $@

$(SRC)/truthtable.c:
	mkdir -p $(dir $@)
	sed '{s/USER/$(LOGNAME)/;}' data/stub.c > $@

pa4.tar: $(FILES)
	tar -vczf $@ $^

archive: pa4.tar
	./grader.py -a $^
