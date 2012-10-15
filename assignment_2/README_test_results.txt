README_test_results.txt

Ryan Nash, 10/10/2012

The "text_container" typedef allows you to change the stl container by just changing it in the scribe.h file once.  I ran the main program (built with 'make timer_test') 3 times for each container. At small levels the times were so insignificant I had to run the series of edits 50 times in a loop (including file re-opens and such) also using a very large input file (~5,000 lines). These are the results:

List: 
43.13s
42.53s
42.50s

Deque: 
31.58s
31.54s
31.56s

Vector:
29.60s
29.61s
29.48s

Clearly the Vector is the recommended container for this program with deque close by and list trailing. I looked at the memory usage for the program while running and surprisingly, to me, Vector used the least, followed by deque and list. I figured Vector would have a lot more pointers to allow for dynamic resizing, per element access and such, and a lot more memory used to compensate (but increase speed as well). However, it looks like the list used the most memory AND took the longest. Perhaps dealing with the memory bloat, or maybe the way lists handle their deleted and moved around nodes is less efficient than the exponentially resizing vector.