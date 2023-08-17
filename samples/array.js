// arr1 = new Array(10);
let arr = [1, 2, 3, 4, 5, 6, 7];

// tamanho
console.log(arr.length);

// toString
console.log(arr.toString().replaceAll(",", " "));

// inserindo no final
arr.push(8);
console.log(arr);

// juntando com um caracter
console.log(arr.join(" _ "));

// removendo o ultimo
arr.pop();
console.log(arr);

// remove e o corrige o primeiro elemento
arr.shift();
console.log('shift:', arr);

// adicionar no inicio corrigndo o array
arr.unshift(10);
console.log(arr);

// cuidado isto serve para dar push
arr[arr.length] = 8;
delete arr[0];

arrToMerge = [10, 20, 30, 40];
const concatedArr = arr.concat(arrToMerge);
// arr = arr.concat(arrToMerge);
console.log(concatedArr);

fruits = ["uva", "banana", "melancia", "pera"];
// (1) eh a posicao que sera afetada com os novos elementos
// (2) eh a quantidade de elementos que vao sair com a entrada dos novos
fruits.splice(1, 2, "kiwi", "maca");
console.log(fruits);

slicedFruits = fruits.slice(1);
slicedFruits2 = fruits.slice(1, 2);
console.log(slicedFruits);
console.log(slicedFruits2);

// Action: (any) => void
const printFunction = (value) => console.log(value)
arr.forEach(printFunction);

console.log("For Each: ")

arr.forEach((value, index) => console.log(`${index} > ${value}`))
const modified = arr.forEach((value) => 2*value)
console.log(modified)
console.log(arr.some((value) => value >= 9))

// Function: (T) => (R)
mappedArr = arr.map((num) => 2 * num)
console.log(mappedArr);

const employeeArr = [
  {
    name: "Pedro",
    job: {
      name: "Developer",
      time: "2 months age",
      company: {
        name: "Santander",
        createdAt: "2023-08-06",
      },
    },
  },
  {
    name: "Beatriz",
    job: {
      name: "Human Resources",
      time: "2 months age",
      company: {
        name: "Chat SBT",
        createdAt: "2023-08-06",
      },
    },
  },
  {
    name: "Lucas",
    job: {
      name: "Scrum Analyst",
      time: "2 months age",
      company: {
        name: "Itau",
        createdAt: "2023-08-06",
      },
    },
  },
];

const jobArr = employeeArr.map(({job}) => ({jobName: job.name, company: job.company.name}));

console.log(jobArr);
