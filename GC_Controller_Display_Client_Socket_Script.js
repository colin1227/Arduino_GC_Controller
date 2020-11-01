let nano33Socket // = new WebSocket(Your WebSocket server)
const buttonCorrelation = { A: { className: '.a' }, B: { className: '.b' }, X: { className: '.x' }, Z: { className: '.bumper.right' }, CUp: { className: '.stick.right', axis: 'Y', val: -22 }, CRight: { className: '.stick.right', axis: 'X', val: 22 }, CDown: { className: '.stick.right', axis: 'Y',  val: 22 }, R: { className: '.trigger-button.right' }, CLeft: { className: '.stick.right', axis: 'X', val: -22 }, Up: { className: '.stick.left',  axis: 'Y', val: -22 }, Down: { className: '.stick.left', axis: 'Y', val: 22 }, Right: { className: '.stick.left', axis: 'X', val: 22 }, Left: { className: '.stick.left', axis: 'X', val: -22 }, L: { className: '.trigger-button.left' }, start: { className: '.start' }, HardLeft: { className: '.stick.left', axis: 'X', val: -17 }, SoftLeft: { className: '.stick.left', axis: 'X', val: -6 }, SoftRight: { className: '.stick.left', axis: 'X', val: 6 }, HardRight: { className: '.stick.left', axis: 'X', val: 17 }};
const buttonCorrelationValues = Object.values(buttonCorrelation)
const buttonCorrelationKeys = Object.keys(buttonCorrelation)
let dirs = [];
nano33Socket.onmessage = (msg) => {
    const pressedButtons = msg.data.length === 1 ? [msg.data] : msg.data.split(',');
    dirs = [];
    /* 
      When combining movments in the future,
      The first to if statements will need to be refactored, 
      For accounting simultaneous X and Y changes.
    */
    for (let i = 0; i < buttonCorrelationValues.length; i++) {
        const button = document.querySelector(buttonCorrelationValues[i].className);

        // if the button is pressed where is it in the list?
        let isPressed = pressedButtons.indexOf(buttonCorrelationKeys[i]);

        if (isPressed >= 0 && Object.values(buttonCorrelationValues[i]).length > 1) {
        // if stick is moved
        dirs.push(button)
          if (buttonCorrelationValues[i].axis === 'Y') {
          // up or down
          button.style['margin-top'] = `${buttonCorrelationValues[i].val}px`;
            button.style['margin-left'] = '0px';
            button.style.transform = `rotateX(${buttonCorrelationValues[i].val}deg)`;
          } else {
            // left or right
            button.style['margin-left'] =  `${buttonCorrelationValues[i].val}px`;
            button.style['margin-top'] = '0px';
            button.style.transform = `rotateY(${buttonCorrelationValues[i].val}deg)`;
          }
        } else if (isPressed == -1 && Object.values(buttonCorrelationValues[i]).length > 1 && !dirs.includes(buttonCorrelationValues[i].className)) {
          // if stick is NOT moved
          button.style['margin-top'] = '0px';
          button.style['margin-left'] = '0px';
          button.style.transform = 'rotateX(0deg) rotateY(0deg)';
        } else if (isPressed >= 0 && buttonCorrelationValues[i].className.includes('.trigger')) {
          button.style.opacity = 1
        } else if (isPressed >= 0) {
          // if button is pressed
          button.classList.add('pressed');
        } else {
          if (buttonCorrelationValues[i].className.includes('.trigger')) {
            // if button is NOT pressed and is a trigger
            button.style.opacity = 0;
          } else {
            // if button is NOT pressed and is NOT a trigger
            button.classList.remove('pressed');
          }
        }
    }
    
}