#include <algorithm> 
#include <functional> 
#include <iostream> 
#include <string> 
#include <ctime> 

 // ------------------------------------------------------------------------- 
  // A Timer object keeps track of CPU time used since the object was 
  // created or last reset.  It implicitly converts to a double, so it can 
  // be used like this: 
  // 
  //   Timer t;             // begin timing some operation 
  //   Timer t("The consumed time is:  ")  // begin timing and provide result message 
  //   ... 
  //   cout << t;           // print out how much CPU time has elapsed 
  //                        // in seconds 
  // 
  //  If a result message was provided at construction, the message and time is emitted at destruction 
  // --------------------------------------------------------------------------- 
namespace ESTLUtils {
	class Timer  
	{ 
		public: 
		Timer( std::string const & message = std::string(), std::ostream& stream = std::cout )  
		: _start( std::clock() ), _message(message), _stream(&stream) {} 

		~Timer() 
		{ 
			if( !_message.empty() )  (*_stream) << "\nTimer:  " << _message << *this << '\n';  
		} 
		operator double() const  
		{ return std::difftime(std::clock(), _start) / CLOCKS_PER_SEC; } 

		void reset() { _start = std::clock(); }        
		private: 
		std::clock_t    _start; 
		std::string     _message; 
		std::ostream*   _stream; 
	}; 
}  // namespace ESTLUtils
