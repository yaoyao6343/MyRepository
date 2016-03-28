#g++ -Wall -isystem ../gtest-1.7.0/include -pthread $1 ../gtest-1.7.0/libgtest.a
g++ -Wall -I ../gtest-1.7.0/include -L ../gtest-1.7.0 -pthread $1 -lgtest
