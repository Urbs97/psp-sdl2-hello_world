all:
	sudo docker run -v "$(CURDIR)/src":/home/pspdev -w /home/pspdev pspdev/pspdev:latest make

clean:
	rm -f src/*.o src/*.elf src/*.prx src/*.PBP