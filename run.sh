if [ ! -d "build" ] || [ $1 == "--rebuild" ] || [ $1 == "-r" ]; then
  rm -rf build
  mkdir build
  cd build
  cmake ..
  cd ..
fi

cd build
make
./game
cd ..
