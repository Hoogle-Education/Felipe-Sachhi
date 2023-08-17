const employee = {
  name: "Pedro",
  job: {
    name: "Developer",
    time: "2 months age",
    company: {
      name: "Chat SBT",
      createdAt: "2023-08-06",
    },

    drinkCoffe(hour) {
      return hour > 9 && hour < 16 ? "coffee" : "its closed";
    },
  },
};

// sem optional chaining
// const companyOfEmployee = employee.job
//   ? employee.job.company
//     ? employee.job.company.name
//     : "Nao se aplica"
//   : "Nao se aplica";

// const soma = function (a, b) {
//   return a + b;
// };

const soma = (a, b) => a + b;
const ehPar = (number) => number % 2 == 0;

console.log(soma);
console.log(soma(2, 3));

// com optional chaining
const companyOfEmployee = employee.job?.company?.name ?? "Nao se aplica";

console.log(Object.keys(employee));
console.log(Object.values(employee));
console.log("name" in employee);

// const coffeeAction = employee.job?.drinkCoffe
