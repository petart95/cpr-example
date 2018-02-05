/**
 * \file   Job.hpp
 * \author ptrifunovic
 *
 * \brief Declares the Job class.
 *
 * The Job class is used for running a job
 * while the class object is alive.
 */

#ifndef JOB_H
#define JOB_H

#include <functional>
#include <memory>

/**
 * \brief The Job class is used for running a job.
 *
 * The Job class creates a thread when it is created 
 * and joins it when it is destoryed.
 *
 * The Job class executes the specifed action
 * while the Job object is alive.
 */
class Job {
public:
	/**
	 * \brief Default constructor.
	 *
	 * Creates a thread that executs the specified job
	 * while the object is alive.
	 *
	 * \param job The job that should be executed 
	 *            while the object is alive
	 * \param init The action that should be executed 
	 *             before starting the job.
	 */
	Job(
		std::function<void()> job = [] {},
		std::function<void()> init = [] {});

	/**
	 * \brief Stops the execution of the specified job
	 */
	void stop();

private:
	// PIMPL idiom
	class Impl;
    std::unique_ptr<Impl, void (*)(Impl *)> pImpl;
};

#endif  // JOB_H