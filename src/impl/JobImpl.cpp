#include <iostream>

#include "impl/JobImpl.hpp"

Job::Impl::Impl(std::function<void()> job, std::function<void()> init) 
	: is_alive(true) {
	thread = std::thread([=] {
		init();
		while (is_alive) {
			try {
				job();
			} catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}
	});
}

void Job::Impl::stop() {
	is_alive = false;
}

Job::Impl::~Impl() {
	//stop();
	thread.join();
}
