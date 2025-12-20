DOXYGEN?=/Applications/Doxygen.app/Contents/Resources/doxygen
VERSION_NUMBER?=

all: ../html

version_number:
	cat Doxyfile | sed 's/PROJECT_NUMBER         =.*/PROJECT_NUMBER         = "$(VERSION_NUMBER)"/g' > new.Doxyfile && \
	rm Doxyfile && \
	mv new.Doxyfile Doxyfile

../html: version_number
	cd ../.. ; $(DOXYGEN) ./docs/doxygen/Doxyfile

clean:
	rm -rf ../html
