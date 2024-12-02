const textOutput = document.getElementById('text-output');

class Character{ //Personagem
    constructor(name, health, power){
        this.name = name; //nome
        this.health = health; //saúde
        this.power = power; //poder
    }

    showInfo(){
        textOutput.innerHTML = `Nome: ${this.name} | HP: ${this.health} | Poder: ${this.power}`;
    }

    attack(){
        textOutput.innerHTML = `${this.name} está efetuando um ataque!`;
    }

    takeDamage(damage){ //Tomar dano
        this.health -= damage;
    }
}

/////////////

class Warrior extends Character{
    constructor(name){
        super(name, 150, 20);
        this.resistence = 50;
    }
    
    showInfo(){
        textOutput.innerHTML = `Nome: ${this.name} | HP: ${this.health} | Poder: ${this.power} | Resistência: ${this.resistence}`;
    }

    attack(target){
        let damage = Math.floor(Math.random() * 100);
        if(this.resistence == 50){
            textOutput.innerHTML = `O gerreiro ${this.name} efetuou um ataque especial! Dano: ${damage * 3}`;
            this.resistence -= 5;
            target.takeDamage(damage * 3);
        }
         else{
            textOutput.innerHTML = `O gerreiro ${this.name} efetuou um ataque! Dano: ${damage}`;
            target.takeDamage(damage);
         }
    }
}

class Sorcerer extends Character{
    constructor(name){
        super(name, 100, 35);
        this.mana = 100;
    }

    showInfo(){
        textOutput.innerHTML = `Nome: ${this.name} | HP: ${this.health} | Poder: ${this.power} | Mana: ${this.mana}`;
    }

    attack(target){
        let damage = Math.floor(Math.random() * 200);
        if(this.mana >= 20 && this.power == 35){
            textOutput.innerHTML = `O feiticeiro ${this.name} efetuou um ataque especial! Dano: ${damage * 2}`;
            this.resistence -= 20;
            target.takeDamage(damage * 2);
        }
         else{
            textOutput.innerHTML = `O feiticeiro ${this.name} efetuou um ataque! Dano: ${damage}`;
            target.takeDamage(damage);
         }
    }
}

class Healer extends Character{
    constructor(name){
        super(name, 120, 50);
        this.faith = 100;
    }

    showInfo(){
        textOutput.innerHTML = `Nome: ${this.name} | HP: ${this.health} | Poder: ${this.power} | Fé: ${this.faith}`;
    }

    attack(target){
        let damage = Math.floor(Math.random() * 50);
        textOutput.innerHTML = `O curandeiro ${this.name} efetuou um ataque! Dano: ${damage}`;
        target.takeDamage(damage)
    }
}

class Boss extends Character{
    constructor(name){
        super(name, 10000, 100);
        this.rage = 0;
    }

    takeDamage(damage){
        this.health -= damage;
        this.getRage();
    }

    getRage(){
        this.rage += 10;
    }

    showInfo(){
        textOutput.innerHTML = `${this.name} tem ${this.health} de vida e fúria ${this.rage}`;
    }

    attack(target){
        let damage = Math.floor(Math.random() * (100 + this.rage));
        textOutput.innerHTML = `${this.name} efetuou um ataque em ${target.name} com dano de ${target.damage}`;
        target.takeDamage(damage);
    }
}

/////////////


const characters = [];

const w1 = new Warrior("Leopoldo");
const s1 = new Sorcerer("Baltazar");
const h1 = new Healer("Ancião");
const b1 = new Boss("Balor");

//Botões de ataque:

const buttonWarriorAttack = document.getElementById("warrior-attack");
const buttonSorcererAttack = document.getElementById("sorcerer-attack");
const buttonHealerAttack = document.getElementById("healer-attack");

const buttonBossAttack = document.getElementById("boss-attack");

//Botões de info:

const buttonWarriorInfo = document.getElementById("warrior-info");
const buttonSorcererInfo = document.getElementById("sorcerer-info");
const buttonHealerInfo = document.getElementById("healer-info");

const buttonBossInfo = document.getElementById("boss-info");

//Eventos - Atacar:

buttonWarriorAttack.addEventListener('click', () => {
    w1.attack(b1);
});

buttonSorcererAttack.addEventListener('click', () => {
    s1.attack(b1);
});

buttonHealerAttack.addEventListener('click', () => {
    h1.attack(b1);
});

buttonBossAttack.addEventListener('click', () => {
})

//Eventos - Mostrar Info:

buttonWarriorInfo.addEventListener('click', () => {
    w1.showInfo();
});

buttonSorcererInfo.addEventListener('click', () => {
    s1.showInfo();
});

buttonHealerInfo.addEventListener('click', () => {
    h1.showInfo();
});

buttonBossInfo.addEventListener('click', () => {
    b1.showInfo();
})


// characters.push(w1, s1, b1);

// function renderizar(characters){
//     const container = document.getElementById("container");

//     container.innerHTML = "";

//     characters.forEach(character => {
//         const p = document.createElement('p');
//         const button = document.createElement('button');
//         button.innerText = "Atacar!";

//         p.innerText = character.showInfo();

//         container.appendChild(p); //O 'p' agora não está solto na página, está incluso dentro do 'container'
//     });
// }

// renderizar(characters);