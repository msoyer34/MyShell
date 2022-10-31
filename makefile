BUILDDIR = build
all: 
	rm -rf $(BUILDDIR)
	mkdir $(BUILDDIR)
	g++ -I $(PWD)/include $(PWD)/src/*.cpp -o $(BUILDDIR)/Project1
clean:
	rm -rf $(BUILDDIR)