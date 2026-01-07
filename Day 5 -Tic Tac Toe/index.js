const board = Array(9).fill(null);
let currentPlayer = 'X';
let gameActive = true;
const winningConditions = [
    [0,1,2], [3,4,5], [6,7,8],
    [0,3,6], [1,4,7], [2,5,8],
    [0,4,8], [2,4,6]
];

const statusEl = document.getElementById('status');
const boardEl = document.getElementById('board');
const resetBtn = document.getElementById('reset');
const overlayEl = document.getElementById('overlay');

boardEl.addEventListener('click', handleCellClick);
resetBtn.addEventListener('click', resetGame);

function handleCellClick(e) {
    const cell = e.target.closest('.cell');
    if (!cell || !gameActive || board[cell.dataset.index]) return;

    const index = cell.dataset.index;
    placeMark(cell, index);
    checkResult();
}

function placeMark(cell, index) {
    board[index] = currentPlayer;
    cell.classList.add(currentPlayer.toLowerCase());
    
    // SVG for X and O
    const svg = document.createElementNS('http://www.w3.org/2000/svg', 'svg');
    svg.setAttribute('viewBox', '0 0 100 100');
    svg.classList.add('mark-svg');
    
    if (currentPlayer === 'X') {
        const line1 = document.createElementNS('http://www.w3.org/2000/svg', 'line');
        line1.setAttribute('x1', '15');
        line1.setAttribute('y1', '15');
        line1.setAttribute('x2', '85');
        line1.setAttribute('y2', '85');
        line1.setAttribute('stroke', '#ff6b6b');
        line1.setAttribute('stroke-width', '12');
        line1.setAttribute('stroke-linecap', 'round');
        line1.style.animation = 'drawX 0.4s ease-out forwards';
        
        const line2 = line1.cloneNode();
        line2.setAttribute('x1', '15');
        line2.setAttribute('y1', '85');
        line2.setAttribute('x2', '85');
        line2.setAttribute('y2', '15');
        line2.style.animationDelay = '0.2s';
        
        svg.append(line1, line2);
    } else {
        const circle = document.createElementNS('http://www.w3.org/2000/svg', 'circle');
        circle.setAttribute('cx', '50');
        circle.setAttribute('cy', '50');
        circle.setAttribute('r', '35');
        circle.setAttribute('fill', 'none');
        circle.setAttribute('stroke', '#4ecdc4');
        circle.setAttribute('stroke-width', '12');
        circle.setAttribute('stroke-linecap', 'round');
        circle.style.animation = 'drawO 0.5s ease-out forwards';
        svg.appendChild(circle);
    }
    
    cell.appendChild(svg);
    currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
    statusEl.textContent = `Player ${currentPlayer}'s turn`;
}

function checkResult() {
    let winner = null;
    for (let condition of winningConditions) {
        const [a, b, c] = condition;
        if (board[a] && board[a] === board[b] && board[a] === board[c]) {
            winner = board[a];
            break;
        }
    }
    
    if (winner) {
        gameActive = false;
        statusEl.textContent = `Player ${winner} Wins! 🎉`;
        statusEl.style.color = winner === 'X' ? '#ff6b6b' : '#4ecdc4';
        showWinLine();
        boardEl.classList.add('draw-shake'); // Reuse shake for win
        return;
    }
    
    if (!board.includes(null)) {
        gameActive = false;
        statusEl.textContent = 'It\'s a Draw! 🤝';
        statusEl.style.color = '#f9ca24';
        boardEl.classList.add('draw-shake');
    }
}

function showWinLine() {
    overlayEl.classList.remove('hidden');
    const line1 = overlayEl.querySelector('.line1');
    const line2 = overlayEl.querySelector('.line2');
    line1.style.stroke = currentPlayer === 'X' ? '#ff6b6b' : '#4ecdc4';
    line2.style.stroke = line1.style.stroke;
}

function resetGame() {
    board.fill(null);
    currentPlayer = 'X';
    gameActive = true;
    statusEl.textContent = "Player X's turn";
    statusEl.style.color = '';
    boardEl.classList.remove('draw-shake');
    overlayEl.classList.add('hidden');
    
    document.querySelectorAll('.cell').forEach(cell => {
        cell.className = 'cell';
        cell.innerHTML = '';
    });
}
