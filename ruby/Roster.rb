require './Student.rb'
require "./Degree.rb"
class Roster
    @studentRoster
    @totalStudents

    def initialize()
           @studentRoster = Array[]
           @totalStudents = 0 
    end

    def studentRoster
      @studentRoster
    end

    def parseString(data)
          array = data.split(",")
          if(array[8] == "SECURITY")
            degree = Degree::SECURITY   
          elsif(array[8] == "NETWORK")
            degree = Degree::NETWORK  
          else
            degree = Degree::SOFTWARE
          end

          addStudent(array[0], array[1], array[2], array[3], array[4], [array[5], array[6], array[7]], degree)
    end

    def addStudent(id,  firstName,  lastName,  emailAddress,  age, coursedays,  degreeprogram)
            student = Student.new(id, firstName, lastName, emailAddress, age, degreeprogram, coursedays)
            @studentRoster.push(student)
            @totalStudents += 1
       
    end

    def removeStudent(id)
      located = false
      @studentRoster.each do |student|
        if(student.id() == id)
          @studentRoster.delete(student)
          @totalStudents -= 1
          located = true
        end  
      end
      if (located == false)
        puts "The student with the ID: " + id + " was not found." 
      end
    end
    
    def printAllStudents()
            @studentRoster.each do |student|
              student.Print()
            end
    end

    def printAverageDaysInCourse(id)
      totaldays = 0
      
      @studentRoster.each do |student|
        if(student.id() == id)
          student.CourseDays().each do |day|
            totaldays += Integer(day)
          end
        end  
      end
      averageDays = totaldays / 3
      puts "Student ID: " + id + ", Average days in course is: " + String(averageDays)
    end

    def printInvalidEmails()
      @studentRoster.each do |student|
       email = student.Email()
       if(email.include? " " or not email.include? "."or not email.include? "@")
                 puts email + " - Is invalid."
       end
      end
    end

    def printByDegreeProgram(degree)
      @studentRoster.each do |student|
        if student.Student_Degree() == degree 
          student.Print()
        end
      end
    end
end