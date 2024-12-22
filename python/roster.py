from student import Student
from degree import Degree

class Roster:
    studentRoster = []
    totalStudents = 0

    def parseString(self, data):
        array = data.split(',')
        degree = None

        if(array[8] == "SECURITY"):
            degree = Degree.SECURITY
        elif(array[8] == "NETWORK"):
            degree = Degree.NETWORK
        else:
            degree = Degree.SOFTWARE
        

        self.addStudent(array[0], array[1], array[2], array[3], array[4], [array[5],array[6], array[7]], degree)
    

    def addStudent(self, id,  firstName,  lastName,  emailAddress,  age, coursedays,  degreeprogram):
        student = Student(id, firstName, lastName, emailAddress, age, degreeprogram, coursedays)
        self.studentRoster.append(student)
        self.totalStudents = self.totalStudents + 1
        
    
    def removeStudent(self, id):
        located = False
        for x in range(self.totalStudents):
            if self.studentRoster[x - 1].getID() == id:
                del self.studentRoster[x - 1]
                self.totalStudents = self.totalStudents - 1
                located = True
        if located == False:
           print("The student with the ID: " + id + " was not found.")
        
    
    def printAllStudents(self):
        for student in self.studentRoster:
            student.Print()
        
    
    def printAverageDaysInCourse(self, id):
        totalDays = 0
        averageDays = 0

        for student in self.studentRoster:
            if student.getID() == id:
                for day in student.getCourseDays():
                    totalDays = totalDays + int(day) 
        averageDays = totalDays / 3;

        print("Student ID: " + id + ", Average days in course is: " + str(averageDays))
        
    
    def printInvalidEmails(self): 
        for student in self.studentRoster:
            email = student.getEmail()
            if " " in email or not "@" in email or not "." in email:
                print(email + " - Is invalid.")
        
    
    def printByDegreeProgram(self, degree):
        for student in self.studentRoster:
            if student.getDegree() == degree:
               student.Print()
        