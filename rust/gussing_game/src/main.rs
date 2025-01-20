use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    println!("Guess the num");

    println!("Please input your guess.");

    let secret_num = rand::thread_rng().gen_range(1..=100);
    println!("the secret num is {secret_num}");

    loop {
        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess) // somethind like a String &
            .expect("Failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("you guessed :{}", guess); 

        match guess.cmp(&secret_num) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too large!"),
            Ordering::Equal => {
                println!("That's correct! you win!");
                break;
            }
        }
    }
}
