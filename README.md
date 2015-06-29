# littleDBMS

This is an academic tutorial to help learn DBMS internals by making a DBMS of your own. We plan to cover as a part of this, the various components of a DBMS - Query parser, Storage manager, Logger, locking, optimizer and so on. Let us improvise this with everyone's contribution.

Motivation:

DBMS - Database management system  - the backbone of many applications that have become part of our life.... Database is an organized collection of data and DBMS is the software that helps to store and access this data. It has been around in various forms helping people store and access their data for the last thirty-forty years. When the complexity of applications increased, requirements of a DBMS also changed. Today's systems are capable of handling millions of transactions per second and DBMS had to scale accordingly. Relational DBMS was the most popular DBMS for decades and now for recent application requirements many NoSQL databases have also come up.

DBMS is a fundamental part of every IT enabled industry and it is usually a core course included in every degree/diploma in computer science/IT. An introductory course on DBMS usually covers the use of DBMS, query languages like SQL, designing data models, transactions etc. In the lab for this course, major concentration would be to make students proficient users of DBMS - learn to model data for an arbitary application, learn SQL, database connectivity through programming languages etc. This is very useful when you start working. But If you also know what is going on behind the scenes, it might help you to create better configurations, debug issues, choose better design, research methods to make DBMS more efficient  etc. To really appreciate the complexity of DBMS which most of us take for granted, we need to take a look into the implementation of one! This wiki and supporting files are aimed at helping readers make their own miniature DBMS - littleDBMS - for pure fun! 


#Getting Started
Since this is a learning activity our focus would be on developing everything from scratch, so we may not use many external libraries or so. We will assume reader is familiar with working of DBMS(has taken an introductory course on DBMS) and is comfortable in some programming language. Code snippets given here if any would be based on C language.
	
It is also assumed that has access to any of the standard DBMS textbooks or any competent online resource. Some of the textbooks are listed below
- Fundamentals of database systems - Elmasri and Navathe
- Database system concepts - Silberchatz, Korth, Sudarshan
- Database Management system - Raghu ramakrishnan and Johannes Gerkhe


Disclaimer: Author is just an enthusiast and is no expert in the domain - so any information given here should be cross checked - we cannot be held responsible for any loss/damage incurred due to use of the information. This is just a fun activity and readers must use their better judgment at all times. 


#Pattern of learning
We will build this littleDBMS iteratively by refining and adding new features. Learning activity is divided into multiple phases. In each phase we will try to make some new part of littleDBMS covering a new topic. At the end we should have a fully functional miniature DBMS.
Each phase will consist of these steps
- Read on given topic from any of the suggested resources
- Come up with a simple design to implement one commonly used technique in that section
- Implement them with a specified interface
- Plugin the new component to existing part of little DBMS

So ready to start? https://github.com/rmvpaps/littleDBMS/wiki

Phases
- 1.0 Warm-up
- 1.1 A Simple storage manager
- 1.2 Storing data as tables/Relations
- 1.3 Simple input/output on Relations
- 1.4 Basic relational operations
- 1.5 SQL parser (subset if SQL3)

After this much, we will have a tangible but inefficient product capable of executing queries. The partial code should be available in repository for the same. 

Next stage, we will try to make it more efficient. 

- 2.0 Action plan
- 2.1 Buffer management
- 2.2 Indexing

I will make this up later...
