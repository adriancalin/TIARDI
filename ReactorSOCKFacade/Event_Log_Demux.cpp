#include "stdafx.h"
#include "Event_Log_Demux.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

typedef std::string::size_type str_size;

using namespace std;

Event_Log_Demux::Event_Log_Demux()
{
}

Event_Log_Demux::~Event_Log_Demux()
{
}

string Event_Log_Demux::handle_log(string log)
{
	// Delegate based on event type
	char log_type = log.at(0);
	switch (log_type)
	{
		// Convert buffer to std::string for easier manipulation
	case '1': return get_info(log.substr(2));
	case '2': return insert_info(log.substr(2));
	}
	return "Event unrecognized!";
}

//Method for getting user name from file based on CPR.
string Event_Log_Demux::get_info(std::string id)
{
	string line;
	ifstream myfile("patients.txt");
	if (myfile.is_open())
	{
		//read all the lines
		while (getline(myfile, line))
		{
			stringstream ssLine(line);
			string segment;
			vector<string> seglist; // used for storing the patient cpr & info
			//get the words separated by '-' -> segment)
			while (getline(ssLine, segment, '-'))
			{
				seglist.push_back(segment);
			}
			//is the first value in the vector equal to the cpr we are looking for?
			if (id.compare(seglist[0]) == 0)
			{
				string& patient_name = seglist[1];
				myfile.close();
				return patient_name;
			}
		}

		myfile.close();
	}
	//in case no patient was found with the specified cpr
	return "Patient not found!";
}

//Method for inserting user CPR and name in database. The method also checks if the CPR already exists.
string Event_Log_Demux::insert_info(std::string patient_info)
{
	str_size id_end = patient_info.find("|");
	str_size name_end = patient_info.find("|", id_end + 1);
	auto id = patient_info.substr(0, id_end);
	auto name = patient_info.substr(id_end + 1, name_end);

	string line;
	ifstream myfile("patients.txt");
	if (myfile.is_open())
	{
		//read all the lines
		while (getline(myfile, line))
		{
			stringstream ssLine(line);
			string segment;
			vector<string> seglist; // used for storing the patient cpr & info
			//get the words separated by '-' -> segment)
			while (getline(ssLine, segment, '-'))
			{
				seglist.push_back(segment);
			}
			//is the first value in the vector equal to the cpr we are looking for?
			if (id.compare(seglist[0]) == 0)
			{
				myfile.close();
				return "Entry with that CPR already exists!";
			}
		}
		myfile.close();

		ofstream myfile("patients.txt", ios::app);
		string entry = "\n";
		entry += id;
		entry += "-";
		entry += name;
		myfile.write(entry.c_str(), entry.length());
		myfile.close();
		return "Entry inserted!";
	}
	return "Issues with the file. Please try again!";
}
