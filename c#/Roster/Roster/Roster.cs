using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Roster
{
    class Roster
    {

        public Student[] StudentRoster = new Student[0];

        public void parseString(string data)
        {
            string[] array = data.Split(",");
            Degree degree;
            int[] days = { int.Parse(array[5]), int.Parse(array[6]), int.Parse(array[7]) };

            if (array[8] == "SECURITY")
            {
                degree = Degree.SECURITY;
            }
            else if (array[8] == "NETWORK")
            {
                degree = Degree.NETWORK;
            }
            else
            {
                degree = Degree.SOFTWARE;
            }

            addStudent(array[0], array[1], array[2], array[3], int.Parse(array[4]), days, degree);
            return;
        }

        public void addStudent(string id, string firstname, string lastname, string email, int age, int[] coursedays, Degree degree) 
        {
            Student student = new Student(id, firstname, lastname, email, age, degree, coursedays);
            Array.Resize(ref StudentRoster, StudentRoster.Length + 1);
            StudentRoster[StudentRoster.GetUpperBound(0)] = student;
            return;
        }

        public void removeStudent(string id)
        {
            for(int i =0; i < StudentRoster.Length; i++)
            {
                if (StudentRoster[i].getID() == id)
                {
                    StudentRoster = StudentRoster.Where((source, index) => index != i).ToArray();
                }
            }
        }

        public void printAllStudents() 
        { 
            foreach (Student student in StudentRoster)
            {
                student.Print();
            }
            return;
        }

        public void printAverageDaysInCourse(string id)
        {
            int totalDays = 0;

            foreach (Student student in StudentRoster)
            {
                if(student.getID() == id)
                {
                    foreach (int day in student.getCourseDays())
                    {
                        totalDays += day;
                    }
                }
            }

            int averageDays = totalDays / 3;
            Console.WriteLine("Student ID: " + id + ", Average days in course is: " + averageDays);
            return;
        }

        public void printInvalidEmails()
        {
            foreach (Student student in StudentRoster)
            {
                string email = student.getEmail();

                if (email.Contains(" ") || !email.Contains("@") || !email.Contains("."))
                {
                    Console.WriteLine(email + " - Is invalid.");
                }
            }
            return;
        }

        public void printByDegreeProgram(Degree degree)
        {
            foreach (Student student in StudentRoster)
            {
                if(student.getDegree() == degree)
                {
                    student.Print();
                }
            }
            return;
        }

    }
}
