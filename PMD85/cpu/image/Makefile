all: disk.img
./mnt:
	mkdir ./mnt
# Obraz disku si pripravime standardni unixovou metodou. Minimalni velikost je 66x512 byte
disk.img: ./mnt
	./create_new disk.img
	sudo losetup /dev/loop0 ./disk.img
	sudo mkfs.vfat -v -F 12 -f 1 -r 128 -S 4096 -s 1 -n LOADER /dev/loop0
	sudo mount /dev/loop0 ./mnt
	sudo cp -r ./fil/* ./mnt
	sudo sync
	sudo sleep 1
	sudo umount ./mnt
	sudo losetup -d /dev/loop0

