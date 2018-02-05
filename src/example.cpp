/*#include <chrono>
#include <thread>

#include "exchange/Poloniex.hpp"
#include "exchange/Bittrex.hpp"
#include "strategy/FrequencyStrategy.hpp"

auto start = std::chrono::steady_clock::now();

void strategy()
{
	auto end = std::chrono::steady_clock::now();
	auto elapsed =
		std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << (elapsed.count() / 1e9) << '\n';
	start = std::chrono::steady_clock::now();
}

void init()
{
	std::cout << "STARTIING 2" << std::endl;
	start = std::chrono::steady_clock::now();
}
*/

#include <iostream>

#define __NARGS(_0,_1,_2,_3,_4,_5,N,...) N
#define NARGS(...) __NARGS(0, ## __VA_ARGS__, 5,4,3,2,1,0)

// Make a FOREACH macro
#define FE_0(WHAT, INIT, X, ...) 
#define FE_1(WHAT, INIT, X, ...) INIT(X) 
#define FE_2(WHAT, INIT, X, ...) WHAT(X) FE_1(WHAT, INIT, __VA_ARGS__)
#define FE_3(WHAT, INIT, X, ...) WHAT(X) FE_2(WHAT, INIT, __VA_ARGS__)
#define FE_4(WHAT, INIT, X, ...) WHAT(X) FE_3(WHAT, INIT, __VA_ARGS__)
#define FE_5(WHAT, INIT, X, ...) WHAT(X) FE_4(WHAT, INIT, __VA_ARGS__)
//... repeat as needed

#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME 
#define FOR_EACH_INIT(ACTION, INIT, ...) \
CONCAT(FE_, NARGS(__VA_ARGS__))(ACTION, INIT, __VA_ARGS__)

#define FOR_EACH(ACTION, ...) \
  FOR_EACH_INIT(ACTION, ACTION,__VA_ARGS__)

template<typename T> struct argument_type;
template<typename T, typename U> struct argument_type<T(U)> { typedef U type; };
#define DCL(__TYPE__, __NAME__) argument_type<void(__TYPE__)>::type __NAME__
#define VAR(__TYPE__, __NAME__) __NAME__

#define _DCL_INIT(A) DCL A
#define _DCL(A) _DCL_INIT(A) ,
#define _VAR_INIT(A) VAR A
#define _VAR(A) _VAR_INIT(A) <<

#define _CONCAT(A, B) A ## B
#define CONCAT(A, B) _CONCAT(A, B)

#define IF_EMPTY0(EMPTY, STANDARD) EMPTY
#define IF_EMPTY1(EMPTY, STANDARD) STANDARD
#define IF_EMPTY(VALUE, EMPTY, STANDARD) \
CONCAT(IF_EMPTY, NARGS(VALUE))(EMPTY, STANDARD) <VALUE> <NARGS(VALUE)>

#define IS_VOID_void()
#define IF_VOID(VALUE, VOID, STANDARD) \
IF_EMPTY(CONCAT(IS_VOID_, VALUE)(), VOID, STANDARD)

#define TEST(...) \
void test(FOR_EACH_INIT(_DCL, _DCL_INIT, __VA_ARGS__)) { \
	std::cout << FOR_EACH_INIT(_VAR, _VAR_INIT, __VA_ARGS__) << std::endl; \
}

TEST(((std::string), s), (std::string, b), (std::string, V))

#include "pimpl.hpp"

class tata : pimpl<tata> {
public:
	void func();
};

#define PIMPLE_CLASS tata

template<>
struct PIMPL_IMPL {
	void func();
};

void PIMPLE_CLASS::func() {
	pimpl<tata>::pImpl->func();
}

void PIMPL_IMPL::func() {
	std::cout << "TATA" << std::endl;
}

int main(int argc, char** argv) {
	test("pozz", "aaaaa", "FSDFA");
	std::cout << IF_VOID(void, "jeste", "nije") << std::endl;
	tata ta;
	ta.func();
	//Poloniex t("BTC", "EMC2");

	//Poloniex a{"BTC", "EMC2"};
	//Bittrex b{"BTC", "EMC2"};
	//Bittrex bittrex{"BTC", "EMC2"};

	//std::this_thread::sleep_for(std::chrono::seconds(5));

	//FrequencyStrategy strategy{{&poloniex, &bittrex}};

	//NonblockingStrategy st({&a}, strategy, init);

	//while(true);
}
