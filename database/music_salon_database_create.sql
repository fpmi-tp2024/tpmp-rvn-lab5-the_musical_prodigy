-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2024-04-08 17:35:55.813

-- tables
-- Table: AUTHOR
CREATE TABLE AUTHOR (
    author_id integer NOT NULL CONSTRAINT AUTHOR_pk PRIMARY KEY,
    name text NOT NULL
);

-- Table: CD
CREATE TABLE CD (
    CD_id integer NOT NULL CONSTRAINT CD_pk PRIMARY KEY,
    manufacture_year integer NOT NULL,
    manufacturer text NOT NULL,
    amount_in_stock integer NOT NULL,
    price real NOT NULL
);

-- Table: MUSICAL_COMPOSITION
CREATE TABLE MUSICAL_COMPOSITION (
    id integer NOT NULL CONSTRAINT MUSICAL_COMPOSITION_pk PRIMARY KEY,
    composition_name text NOT NULL,
    author_id integer NOT NULL,
    performer_id integer NOT NULL,
    CONSTRAINT MUSICAL_COMPOSITION_AUTHOR FOREIGN KEY (author_id)
    REFERENCES AUTHOR (author_id),
    CONSTRAINT MUSICAL_COMPOSITION_PERFORMER FOREIGN KEY (performer_id)
    REFERENCES PERFORMER (performer_id)
);

-- Table: OPERATION
CREATE TABLE OPERATION (
    operation_id integer NOT NULL CONSTRAINT OPERATION_pk PRIMARY KEY,
    operation_type_id integer NOT NULL,
    date date NOT NULL,
    CONSTRAINT OPERATION_OPERATION_TYPE FOREIGN KEY (operation_type_id)
    REFERENCES OPERATION_TYPE (operation_type_id)
);

-- Table: OPERATION_CDs
CREATE TABLE OPERATION_CDs (
    operation_id integer NOT NULL,
    CD_id integer NOT NULL,
    quantity integer NOT NULL,
    CONSTRAINT OPERATION_CDs_pk PRIMARY KEY (operation_id,CD_id),
    CONSTRAINT OPERATION_CDs_OPERATION FOREIGN KEY (operation_id)
    REFERENCES OPERATION (operation_id),
    CONSTRAINT OPERATION_CDs_CD FOREIGN KEY (CD_id)
    REFERENCES CD (CD_id)
);

-- Table: OPERATION_TYPE
CREATE TABLE OPERATION_TYPE (
    operation_type_id integer NOT NULL CONSTRAINT OPERATION_TYPE_pk PRIMARY KEY,
    operation_name text NOT NULL
);

-- Table: PERFORMER
CREATE TABLE PERFORMER (
    performer_id integer NOT NULL CONSTRAINT PERFORMER_pk PRIMARY KEY,
    name text NOT NULL
);

-- Table: USER
CREATE TABLE USER (
    user_id integer NOT NULL CONSTRAINT USER_pk PRIMARY KEY,
    user_role_id integer NOT NULL,
    login text NOT NULL,
    password text NOT NULL,
    CONSTRAINT USER_USER_ROLE FOREIGN KEY (user_role_id)
    REFERENCES USER_ROLE (user_role_id)
);

-- Table: USER_ROLE
CREATE TABLE USER_ROLE (
    user_role_id integer NOT NULL CONSTRAINT USER_ROLE_pk PRIMARY KEY,
    role_name text NOT NULL
);

-- Table: m2m_MUSICAL_COMPOSITION_CD
CREATE TABLE m2m_MUSICAL_COMPOSITION_CD (
    CD_id integer NOT NULL,
    musical_composition_id integer NOT NULL,
    CONSTRAINT m2m_MUSICAL_COMPOSITION_CD_pk PRIMARY KEY (CD_id,musical_composition_id),
    CONSTRAINT m2m_MUSICAL_COMPOSITION_CD_CD FOREIGN KEY (CD_id)
    REFERENCES CD (CD_id),
    CONSTRAINT m2m_MUSICAL_COMPOSITION_CD_MUSICAL_COMPOSITION FOREIGN KEY (musical_composition_id)
    REFERENCES MUSICAL_COMPOSITION (id)
);

-- End of file.

