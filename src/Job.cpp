#include "impl/JobImpl.hpp"

Job::Job(
		std::function<void()> job,
		std::function<void()> init) 
	: pImpl(
		new Impl(job, init),
		[] (Impl *impl) {
			delete impl; 
		}
	) 
{
}

void Job::stop() 
{ 
	pImpl->stop();
}
