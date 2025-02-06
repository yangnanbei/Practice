fn main() {
    let s1 = gives_ownership();
    let s2 = String::from("hello");
    let s3 = takes_and_gives_back(s2);
    // s2 is moved into takes_and_gives_back
    // in other word, s2 is dropped
    println!("s1 {s1}, s2 {s2}, s3 {s3}");
}

fn gives_ownership() -> String {
    let something = String::from("yours");
    something
}

fn takes_and_gives_back(a_string: String) -> String {
    a_string
}
