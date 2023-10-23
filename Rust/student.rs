use std::collections::BTreeMap;
use std::io;

struct Student {
    midterm: i32,
    final_exam: i32,
}

fn main() {
    let mut student_map: BTreeMap<String, Student> = BTreeMap::new();

    println!("학생 수를 입력하세요:");
    let mut student_count = String::new();
    io::stdin().read_line(&mut student_count).expect("입력 에러");
    let student_count: i32 = student_count.trim().parse().expect("정수로 변환 에러");

    for _ in 0..student_count {
        let mut input = String::new();
        println!("학생 이름, 중간 점수, 기말 점수를 입력하세요:");
        io::stdin().read_line(&mut input).expect("입력 에러");
        let mut parts = input.trim().split_whitespace();
        let name = parts.next().expect("이름 없음").to_string();
        let midterm: i32 = parts.next().expect("중간 점수 없음").parse().expect("정수로 변환 에러");
        let final_exam: i32 = parts.next().expect("기말 점수 없음").parse().expect("정수로 변환 에러");

        let student = Student {
            midterm,
            final_exam,
        };

        student_map.insert(name, student);
    }

    println!("학생 정보:");
    for (name, student) in &student_map {
        println!(
            "이름: {}, 중간 점수: {}, 기말 점수: {}",
            name, student.midterm, student.final_exam
        );
    }
}