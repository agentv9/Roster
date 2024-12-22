from degree import Degree
class Student:
    id = None
    First_Name = None
    Last_Name = None
    Email = None
    Age = None
    Student_Degree = Degree
    CourseDays = []

    def __init__(self, id, firstname, lastname, email, age, degree, coursedays):
        self.setID(id)
        self.setFirstName(firstname)
        self.setLastName(lastname)
        self.setEmail(email)
        self.setAge(age)
        self.setDegree(degree)
        self.setCourseDays(coursedays)

    def getID(self): return self.id
    def getFirstName(self): return self.First_Name
    def getLastName(self): return self.Last_Name
    def getEmail(self): return self.Email
    def getAge(self): return self.Age
    def getDegree(self): return self.Student_Degree
    def getCourseDays(self): return self.CourseDays

    def setID(self, id): self.id = id
    def setFirstName(self, name): self.First_Name = name
    def setLastName(self, name): self.Last_Name = name
    def setEmail(self, email): self.Email = email
    def setAge(self, age): self.Age = age
    def setDegree(self, degree): self.Student_Degree = degree
    def setCourseDays(self, days): self.CourseDays = days

    def Print(self):
        print(self.getID()+"   "+self.getFirstName()+"   "+self.getLastName()+"   "+self.getEmail()+"   "+self.getAge()+"   "+str(self.getDegree())+"   "+str(self.getCourseDays()))