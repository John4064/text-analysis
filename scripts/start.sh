#John Parkhurst
echo "Start:"
g++ -std=c++17 ../Source/main.cpp ../Source/filep.cpp ../Source/computation.cpp  ../Source/statistics.cpp  ../Source/algorithms.cpp -pthread -o test
./test ../inputs/sun.txt