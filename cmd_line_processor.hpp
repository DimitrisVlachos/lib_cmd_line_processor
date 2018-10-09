/*
    Cmd line processor 
	Dimitrisv22@gmail.com 
	Git : https://github.com/DimitrisVlachos
*/
#ifndef _cmd_line_processor_hpp_
#define _cmd_line_processor_hpp_
#include <vector>
#include <stdint.h>
#include <string.h>
#include <iostream>

class cmd_line_arg_processor_c {
	private:
	std::vector< std::string > m_args;
	size_t m_ptr;

	public:
	cmd_line_arg_processor_c() {
	}
	cmd_line_arg_processor_c(const size_t argc,const char** argp,const bool is_cmd_line = true)   {
		this->init(argc,argp,is_cmd_line); 
	}
	cmd_line_arg_processor_c(const std::vector< std::string >& args )   {
		this->init(args); 
	}
	~cmd_line_arg_processor_c() {
	}

	inline void reset() {
		this->m_ptr = 0;
	}

	inline bool init(const size_t argc,const char** argp,const bool is_cmd_line = true) {
		if (argc < ( (is_cmd_line) ? 2 : 1 ) )
			return false;

		this->m_args.clear();
		this->m_args.reserve(argc);
		for (size_t i = (is_cmd_line) ? 1 : 0;i < argc;++i)
			this->m_args.push_back( std::string(argp[i]) );

		this->m_ptr = 0;
		return true;
	}

	inline bool init(const std::vector< std::string >& args) {
		if (args.size() < 2)
			return false;
		this->m_args = args;
		this->m_ptr = 0;
		return true;
	}

	inline const bool has_more() {
		return (this->m_ptr < this->m_args.size());
	}

	inline const int32_t get_next_int() {
		if (!this->has_more())
			return 0;
		return std::stoi( this->m_args[this->m_ptr++] ) ;
	}

	inline const bool get_next_bool() {
		if (!this->has_more())
			return false;
		return (bool)(1==std::stoi( this->m_args[this->m_ptr++] ));
	}

	inline const double get_next_double() {
		if (!this->has_more())
			return 0.0;
		return std::stod( this->m_args[this->m_ptr++] ) ;
	}

	inline const std::string& get_next_string() {
		static const std::string m_error = "null";
		if (!this->has_more())
			return m_error;
		return this->m_args[this->m_ptr++];
	}
};

#endif

