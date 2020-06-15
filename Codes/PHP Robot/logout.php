<?php
/*
 *  Robi the PHP robot
 *  A control and login interface
 *  Copyright (c) 2020 Maxim Verhoef
 *  contact@maximverhoef.nl
 */

session_start(); //Starting session

session_unset(); //Unset session

session_destroy(); //Destroy session (logout)

header("Location: index.php"); //Redirect to index.php
?>