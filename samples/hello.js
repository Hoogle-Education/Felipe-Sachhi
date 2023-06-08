// truthy: 2, "a", [2, 3]
// falsy: 0, '', [], {}, null, undefined, NaN

// Nullish Coleacing Operator
const employee = {
  name: "John",
  age: 23,
  salary: 0,
  job: null,
};

// const salario1 = employee.salary || "Nao se aplica";
// const salario2 = employee.salary ?? "Nao se aplica";
// console.log(salario1);
// console.log(salario2);

// const { name: firstName, age } = employee;
// console.log(firstName);
// console.log(age);

// jeito simples
function exibeDadosPessoais(employee) {
  console.log(employee.name);
  console.log(employee.age);
}

// com desestruturacao
function exibeDadosPessoaisMelhor({ name: firstName, age }) {
  console.log(firstName);
  console.log(age);
}

// exibeDadosPessoaisMelhor(employee);

// rest operator
// array = [1, 2, 3, 4, 5, 6];
// const [first, , third, fourth, ...rest] = array;
// const { name: firstName, age, ...anotherData } = employee;

// console.log(first, third, fourth);
// console.log(rest);
// console.log(anotherData);

// reestruturacao - short sintax
const dogname = "bob";
const age = 4;
const dog = { name: dogname, age };
console.log(dog);

// stringfy coloca em modelo de string (json)
console.log(JSON.stringify(dog));

// parse desfaz o modelo json
console.log(JSON.parse(JSON.stringify(dog)));
