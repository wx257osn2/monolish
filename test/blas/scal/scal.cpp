#include<iostream>
#include<istream>
#include<chrono>
#include"../../test_utils.hpp"

template <typename T>
void get_ans(double alpha, monolish::vector<T> &mx){

	for(size_t i = 0; i < mx.size(); i++){
		mx[i] = alpha * mx[i];
	}

}

template <typename T>
bool test(const size_t size, double tol, const size_t iter, const size_t check_ans){

	//create random vector x rand(0~1)
	T alpha = 123.0;
   	monolish::vector<T> x(size, 0.0, 1.0);

	monolish::vector<T> ansx = x;

	// check ans
	if(check_ans == 1){
 		get_ans(alpha, ansx);

		x.send();
		monolish::blas::scal(alpha, x);
		x.recv();

		if(ans_check<T>(x.data(), ansx.data(), x.size(), tol) == false){
 			return false;
 		}
	}

	x.send();

	//exec
	auto start = std::chrono::system_clock::now();

	for(size_t i = 0; i < iter; i++){
		monolish::blas::scal(alpha, x);
	}

	auto end = std::chrono::system_clock::now();
	double sec = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1.0e+9;

	std::cout << "total average time[sec]: " << sec / iter << std::endl;

	return true;
}

int main(int argc, char** argv){

	if(argc!=4){
		std::cout << "error $1:vector size, $2: iter, $3: error check (1/0)" << std::endl;
		return 1;
	}
	//monolish::util::set_log_level(3);
	//monolish::util::set_log_filename("./monolish_test_log.txt");

	size_t size = atoi(argv[1]);
	size_t iter = atoi(argv[2]);
	size_t check_ans = atoi(argv[3]);

 	// exec and error check
 	if( test<double>(size, 1.0e-8, iter, check_ans) == false){ return 1; }

 	// exec and error check
 	if( test<float>(size, 1.0e-5, iter, check_ans) == false){ return 1; }

	return 0;
}
