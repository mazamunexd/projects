const resultField = document.getElementById('result');
const buttons = document.querySelectorAll('button');


let currentNumber = '';
let previousNumber = '';
let operator = '';

function updateResultField() {
    resultField.value = currentNumber;
}

function handleNumberClick(number) {
    if (number === '.' && currentNumber.includes('.')) return;
    currentNumber += number;
    updateResultField();
}

function handleOperatorClick(op) {
    previousNumber = currentNumber;
    currentNumber = '';
    operator = op;
}

function handleEqualsClick() {
    let result;
    switch (operator) {
        case '+':
            result = parseFloat(previousNumber) + parseFloat(currentNumber);
            break;
        case '-':
            result = parseFloat(previousNumber) - parseFloat(currentNumber);
            break;
        case 'x':
            result = parseFloat(previousNumber) * parseFloat(currentNumber);
            break;
        case '/':
            result = parseFloat(previousNumber) / parseFloat(currentNumber);
            break;
        default:
            result = 0;
    }
    if (Math.abs(result) >= 100000000) {
        currentNumber = result.toExponential(2);
    } else {
        currentNumber = result.toLocaleString(); 
    }
    previousNumber = '';
    operator = '';
    updateResultField();
}


function handleClearClick() {
    currentNumber = '';
    previousNumber = '';
    operator = '';
    updateResultField();
}


buttons.forEach(button => {
    if (button.classList.contains('number')) {
        button.addEventListener('click', () => handleNumberClick(button.textContent));
    } else if (button.classList.contains('operator')) {
        button.addEventListener('click', () => handleOperatorClick(button.textContent));
    } else if (button.classList.contains('equals')) {
        button.addEventListener('click', handleEqualsClick);
    } else if (button.classList.contains('clear')) {
        button.addEventListener('click', handleClearClick);
    } else if (button.classList.contains('decimal')) {
        button.addEventListener('click', () => handleNumberClick('.'));
    }
});
