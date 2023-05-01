ePlusEminus: ePlusEminus.cc
	clang++ $@.cc -o $@ -I/opt/homebrew/Cellar/pythia/8.308/include `root-config --cflags` -O2 -std=c++17 -pedantic -W -Wall -fPIC -pthread -L/opt/homebrew/Cellar/pythia/8.308/lib -Wl,-rpath,/opt/homebrew/Cellar/pythia/8.308/lib -lpythia8 -ldl `root-config --glibs`
