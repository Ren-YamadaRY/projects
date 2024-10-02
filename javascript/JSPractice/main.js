const Person = {
    name: "John",
    age: 30,
    address: {
        city: "東京",
        sipcode: "123-4567"
    },
    hobbies: ["読書", "映画鑑賞", "ゲーム"]
};

const greet = (person) => {
    return `Hello, ${person.name}!`;
}

console.log(greet(Person));