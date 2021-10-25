<template>
    <n-layout style="height: 100vh;">
        <n-layout-header style="height: 64px;" bordered>
        </n-layout-header>
        <n-layout position="absolute" style="top: 64px; bottom: 64px;" has-sider>
            <Sider></Sider>
            <n-layout content-style="padding: 0px;">
                <Main></Main>
            </n-layout>
        </n-layout>
        <n-layout-footer position="absolute" style="height: 64px; padding: 24px;" bordered>
        </n-layout-footer>
    </n-layout>
</template>

<script>
import {Main} from "@/components/layout/components/Main/index.ts";
import {Sider} from "@/components/layout/components/Sider/index.ts";

export default {
    name: "Layout",
    components: {
        Main,
        Sider
    }
}
</script>

<style scoped>

</style>