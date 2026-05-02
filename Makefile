all:
	meson compile -C build && ./build/mesoncreate

setup:
	meson setup build

build:
	meson compile -C build

clean:
	rm -rf .cache && rm -rf build/

run:
	./build/mesoncreate

.PHONY: all build
