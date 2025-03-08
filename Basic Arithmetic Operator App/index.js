const operators = {
    '+': (a, b) => a + b,
    '-': (a, b) => a - b,
    '*': (a, b) => a * b,
    '/': (a, b) => parseFloat((a / b).toFixed(2)), // Use toFixed(2) for division
  };
  
  const num1 = Math.ceil(Math.random() * 100);
  const num2 = Math.ceil(Math.random() * 50);
  
  const operator = Object.keys(operators)[Math.floor(Math.random() * Object.keys(operators).length)];
  
  const questionEl = document.getElementById("question");
  
  const inputEl = document.getElementById("input");
  
  const formEl = document.getElementById("form");
  
  const scoreEl = document.getElementById("score");
  
  let score = JSON.parse(localStorage.getItem("score"));
  
  if (!score) {
    score = 0;
  }
  
  scoreEl.innerText = `score: ${score}`;
  
  questionEl.innerText = `What is ${num1} ${operator} ${num2}?`;
  
  const correctAnswer = operators[operator](num1, num2);
  
  formEl.addEventListener("submit", () => {
    const userAnswer = parseFloat(inputEl.value); // Use parseFloat for division
    if (Math.abs(userAnswer - correctAnswer) < 0.001) { // Check for floating point precision
      score++;
      updateLocalStorage();
    } else {
      score--;
      updateLocalStorage();
    }
    generateNewQuestion(); // Generate a new question after submission
  });
  
  function updateLocalStorage() {
    localStorage.setItem("score", JSON.stringify(score));
    scoreEl.innerText = `score: ${score}`;
  }
  