public class Bob {
	public static void main(String[] args) {
		User user1 = new User("Alice");
		User user2 = new User("Bob");
		System.out.println(user2.name.equals("Bob"));
	}
}

class User {
	String name;

	User(String name) {
		this.name = name;
	}
}