Create database ClawMachine;
use ClawMachine;

-- Table Creations 

create table Entrada(
	idEntrada int not null auto_Increment unique,
    primary Key (idEntrada),
    descripcion varchar(10)
);

create table Salida(
	idSalida int not null auto_Increment unique,
    primary Key (idSalida),
    descripcion varchar(10)
);

create table Juego(
	idJuego int unique not null auto_increment,
    primary key(idJuego),
    tipoEntrada int not null,
    tipoSalida int not null,
    diafecha int not null,
    mesfecha int not null,
    hora int not null,
    constraint tipoEntrada_FK foreign key (tipoEntrada)  references entrada(idEntrada),
    constraint tipoSalida_FK foreign Key (tipoSalida) references salida(idSalida)
);


-- Input and output defaults

insert into Entrada(descripcion) values("Valido"),("Invalido"),("Fraude");

insert into Salida(descripcion) values ("Positiva"),("Negativa"),("Invalida");

