all:
	meson compile -C build && ./build/mesoncreate

build: 
	meson setup build 

clean:
	rm -rf .cache && rm -rf build/

run:
	./build/mesoncreate

# test:
# 	meson test -C build
#

.PHONY: all build


