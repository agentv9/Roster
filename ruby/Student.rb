class Student
  def initialize(id, name1, name2, email, age, degree, days)
    @id = id
    @First_Name = name1
    @Last_Name = name2
    @Email = email
    @Age = age
    @Student_Degree = degree
    @CourseDays = days
  end

  def id
    @id
  end
  def First_Name
    @First_Name
  end
  def Last_Name
    @Last_Name
  end
  def Email
    @Email
  end
  def Age
    @Age
  end
  def Student_Degree
    @Student_Degree
  end
  def CourseDays
    @CourseDays
  end

  def id=(id)
    @id = id
  end
  def First_Name=(name)
    @First_Name = name
  end
  def Last_Name=(name)
    @Last_Name = name
  end
  def Email=(email)
    @Email = email
  end
  def Age=(age)
    @Age = age
  end
  def Student_Degree=(degree)
    @Student_Degree = degree
  end
  def CourseDays=(days)
    @CourseDays = days
  end

  def Print
    puts "#@id  #@First_Name  #@Last_Name  #@Email  #@Age #@Student_Degree  #@CourseDays"
  end

end