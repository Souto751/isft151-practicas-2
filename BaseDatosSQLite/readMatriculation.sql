SELECT subject.name, subject.year, teacher.first_name AS teacherName, teacher.last_name AS teacherLastname, student.first_name AS studentName, student.last_name AS studentLastname FROM subject_has_members
INNER JOIN subject ON subject.id = subject_has_members.subject_id
INNER JOIN teacher ON teacher.id = subject_has_members.teacher_id
INNER JOIN student ON student.id = subject_has_members.student_id;