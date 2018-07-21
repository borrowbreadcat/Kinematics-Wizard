# Kinematics-Wizard

STICKY
A program that solves newtonian kinematics algebra problems automatically. Things like initial velocity, how long is it falling, how far did it travel, etc. 

==========================================================
2018 July 19

I have written the program up to a working version.  It should be available to download off of this site.  

I made a lot of programming no-nos along the way, and the product still has a major issue involved with rounding floating point variables.  

KNOWN ISSUES:

programming no-no:
I created variables outside of the functions; I'm pretty sure that's what's called "global variables" and it's generally frowned upon because of the massive all-encompassing scope they carry.  

rounding issue:
It is a known, well-documented hurdle for everyone in computer science fields.  Floating point variables are calculated in base-2 (binary) but represented in base-10 (decimal).  As a simple example, consider the base-ten numbers 0.1 and 0.33333-repeating.  0.1 is a precise representation of the number whereas 0.33333 is only an approximation for the actual number 0.33333-repeating.  In base 10, we are not able to precisely calculate with 0.3-repeating without some rounding involved.  The base-ten number 0.1 cannot be represented precisely in base-two.  Instead it is a repeating fraction which must be rounded for calculations, much the way base-ten calculations handle 0.3-repeating.  So when the user tells the program that acceleration is equal to 9.8, that number is converted from decimal to binary (rounded if necessary) before it is used in calculations.  While it usually results in minor inaccuracies, when the rounded floating point value is used in division or square root calculations, occasionally the final answer may be very inaccurate.

pointers and data structures:
While I was writing the program I noticed that I had a distinct issue:  I couldn't figure out how to use one function which calls different variables for help without either passing many values through multiple functions each defined with many, many parameters or setting up a bunch of global variables.  For my skill level, even though I knew it's considered bad practice, it seemed like the path of least resistance to use globals.  Anyway, I think, after doing some research and chatting with Harry, that pointers are a concept I haven't learned yet that might solve my problems.

io structure:
I am fully capable of polishing the user interface.  I could make some wait times, pretty ASCII boxes and dividers, better method of asking questions and collecting responses, et al.  I don't think I'll do this on account of knowing there are some deeper back-end programming issues that need to be addressed.  Coding on top of those before fixing them just makes more work.  It's bad form.  



==========================================================
2018 May 22

In the Chapter 2 comprehensive quiz on learncpp.com, i was asked to write a program that tracks the position of a ball in free fall, given it's initial altitude. It was very satisfying to write and add an improvement or two, and it brought back memories of when I taught algebra based physics to 9th graders. 

It got me thinking that I might, even at this moment, have enough c++ skills to write a more comprehensive program which could calculate algebraic kinematics automatically.  It would ask the user a series of questions about the situation, filling in values and determining what variables are unknown. Then it would provide a list of all the values it can figure out, noting which ones were solved and which were given. It could perhaps then answer other more specific questions like "where was the ball at this given time" or stuff like that. 

It is a bit intimidating, but I think I can do this.
