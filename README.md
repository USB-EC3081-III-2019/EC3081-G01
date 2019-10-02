# PROYECTO: Sistema de automatización de riego
*Este proyecto tiene como finalidad crear un sistemas de control y automatizacion del riego de un invernadero. Utilizando todos y cada uno de los conocimientos que hemos adquirido duranto los ultimos 3 años de la Carrera Tecnología Electronica en la USB, basandonos en la premisa principal de (Sensores --> Control --> Actuadores), seremos capaces de crear un sistema que simule un control total de la humedad de un imbernadero físico.*

## Integrantes del equipo
* 15-11152 Orazio Javier Portillo Gatto
* 12-06824  Bensedi Jose Acosta

# Control de riego

> El control de riego es aquel sistema que provee con agua  a las plantas de un jardín de manera tecnificada por medio de un sistema de aspersión.

> Los riegos por aspersión automatizados, son de gran ayuda en estos años. Cada vez tenemos menos tiempo para dedicarnos a nuestro jardín y necesitamos soluciones prácticas y económicas para aprovecharlo durante el día. Para ahorrar en agua el ideal es regar de noche con menor temperatura, sin viento y mayor presión de agua, lo que es casi impracticable si no se tiene un riego automático.

## Sensores:
> Son aquellos dispositivos que están capacitados para detectar acciones o estímulos externos y responder en consecuencia de dichos estímulos. Es decir, nos permiten captar la información del medio físico que nos rodea. Se encarga de medir las magnitudes físicas y transformarlas en señales eléctricas capaces de ser medidas por un microcontrolador y ser utilizadas posteriormente.

### Sensores a utilizar:
* Humedad y Temperatura (DHT11): [DHT11](https://naylampmechatronics.com/sensores-temperatura-y-humedad/57-sensor-de-temperatura-y-humedad-relativa-dht11.html)
* Fotocelda (LDR): [LDR](https://tuelectronica.es/fotocelda-control-de-dispositivos-con-la-luz/)
>>  Una fotocelda es un dispositivo electrónico que es capaz de producir una pequeña cantidad de corriente eléctrica al ser expuesta a la luz, este dispositivo está compuesto por una fotorresistencia o resistencia LDR (componente electrónico que varía su resistencia con la luz) la cual está fabricada con un material que reacciona a la luz, de esta manera cuando este material recibe la luz cambia su resistividad.  Recordar no confundir la fotocelda con la fotorresistencia LDR, son conceptos diferentes. El primero es un dispositivo de control, y el segundo es un componente fotosensor que permite el funcionamiento del primero. 
>><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/foto_celda.jpg"><img src="https://github.com/USB-EC3081-III-2019/EC3081-G01/blob/master/docs/fotorresistenciaLDR.png">

* Humedad de sustrato:

## Actuadores:
> Son aquellos dispositivos capaces de transformar la energía hidráulica, neumática o eléctrica en la activación de procesos con la finalidad de generar un efecto sobre un proceso automatizado. Este recibe la orden de un regulador o controlador y en función a ella genera la orden para activar un elemento final de control.

### Actuadores a utilizar:
* Reley Godos 831A: [Relay](https://www.datasheet.live/index.php?title=Special:PdfViewer&url=https%3A%2F%2Fpdf.datasheet.live%2F1f8815ae%2Fdatasheet.directory%2F831A-8.pdf)
*



