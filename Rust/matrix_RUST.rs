use std::io;

// 행렬을 더하는 함수
fn add_matrices(matrix_a: &Vec<Vec<i32>>, matrix_b: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut result = Vec::new();
    
    for (row_a, row_b) in matrix_a.iter().zip(matrix_b.iter()) {
        let mut row_result = Vec::new();
        for (&a, &b) in row_a.iter().zip(row_b.iter()) {
            row_result.push(a + b);
        }
        result.push(row_result);
    }

    result
}

fn main() {
    let mut input = String::new();

    // 행렬의 크기 입력
    println!("행렬의 행 수를 입력하세요: ");
    io::stdin().read_line(&mut input).expect("입력 에러");
    let rows: usize = input.trim().parse().expect("숫자로 변환 불가능");

    // 행렬 A 입력
    let mut matrix_a = Vec::new();
    println!("첫 번째 행렬 A의 요소를 입력하세요:");
    for _ in 0..rows {
        input.clear();
        io::stdin().read_line(&mut input).expect("입력 에러");
        let values: Vec<i32> = input
            .split_whitespace()
            .map(|s| s.parse().expect("숫자로 변환 불가능"))
            .collect();
        matrix_a.push(values);
    }

    // 행렬 B 입력
    let mut matrix_b = Vec::new();
    println!("두 번째 행렬 B의 요소를 입력하세요:");
    for _ in 0..rows {
        input.clear();
        io::stdin().read_line(&mut input).expect("입력 에러");
        let values: Vec<i32> = input
            .split_whitespace()
            .map(|s| s.parse().expect("숫자로 변환 불가능"))
            .collect();
        matrix_b.push(values);
    }

    // 두 행렬을 더함
    let result = add_matrices(&matrix_a, &matrix_b);

    // 결과 출력
    println!("두 행렬의 합:");
    for row in &result {
        for &value in row {
            print!("{} ", value);
        }
        println!();
    }
}