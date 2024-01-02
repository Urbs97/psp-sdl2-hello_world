all:
	sudo docker run -v "$(CURDIR)/workspace":/home/pspdev -w /home/pspdev pspdev/pspdev:latest make

clean:
	rm -f workspace/src/*.o workspace/*.elf workspace/*.prx workspace/*.PBP