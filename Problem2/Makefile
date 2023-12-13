all: a2

a2: Date.o Photo.o PhotoArray.o Album.o AlbumArray.o PhotoGram.o Client.o TestView.o TestControl.o main.cc
	g++ -o a2 Date.o Photo.o PhotoArray.o Album.o AlbumArray.o PhotoGram.o Client.o TestView.cc TestControl.o main.cc

Date.o: Date.h Date.cc
	g++ -c Date.cc

Photo.o: Photo.h Photo.cc
	g++ -c Photo.cc

PhotoArray.o: PhotoArray.h PhotoArray.cc
	g++ -c PhotoArray.cc

Album.o: Album.h Album.cc
	g++ -c Album.cc

AlbumArray.o: AlbumArray.h AlbumArray.cc
	g++ -c AlbumArray.cc

PhotoGram.o: PhotoGram.h PhotoGram.cc
	g++ -c PhotoGram.cc

Client.o: Client.h Client.cc
	g++ -c Client.cc

TestControl.o: TestControl.h TestControl.cc
	g++ -c TestControl.cc

Testview.o: TestView.h TestView.cc
	g++ -c TestView.cc

clean:
	rm -f a2 Date.o Photo.o PhotoArray.o Album.o AlbumArray.o PhotoGram.o TestControl.o TestView.o Client.o
